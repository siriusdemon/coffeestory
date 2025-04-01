#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include "coffeestory.h"

static void msleep(int s) {
    std::this_thread::sleep_for(std::chrono::milliseconds(s));
}


// Reset focus to maplestory
HWND MAPLE_WIN;
int LEFT, TOP, RIGHT, BOTTOM = 0;
static void reset_maple() {
    MAPLE_WIN = FindWindow(NULL, "MapleStory");
    RECT rect;
    if (GetWindowRect(MAPLE_WIN, &rect)) {
        LEFT = rect.left;
        TOP = rect.top;
        RIGHT = rect.right;
        BOTTOM = rect.bottom;
    }
    try {
        // Show the window
        ShowWindow(MAPLE_WIN, SW_SHOWNORMAL);
        // Bring the window to the foreground
        SetForegroundWindow(MAPLE_WIN);
    }
    catch (const std::exception& e) {
        std::cerr << "Failed to reset focus: " << e.what() << std::endl;
    }
}


static void leftclick(int x, int y) {
    x += LEFT;
    y += TOP;
    SetCursorPos(x, y);
    msleep(100);
    POINT position;
    GetCursorPos(&position);
    mouse_event(MOUSEEVENTF_LEFTDOWN, position.x, position.y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, position.x, position.y, 0, 0);
    msleep(500);
}

void pressEnter() {
    keybd_event(VK_RETURN, 0, 0, 0);  
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);  
    msleep(500);
}





// Capture the windows
class ScreenshotCapture {
private:
    HDC hdcWindow;      
    HDC hdcMemDC;       
    HBITMAP hbmScreen;  
    HWND hwnd;

    ScreenshotCapture() {
        hwnd = MAPLE_WIN;
        hdcWindow = GetDC(hwnd);
        hdcMemDC = CreateCompatibleDC(hdcWindow);
        RECT rect;
        GetClientRect(hwnd, &rect);
        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;
        hbmScreen = CreateCompatibleBitmap(hdcWindow, width, height);
        SelectObject(hdcMemDC, hbmScreen);
    }

    ScreenshotCapture(const ScreenshotCapture&) = delete;
    ScreenshotCapture& operator=(const ScreenshotCapture&) = delete;

public:
    static ScreenshotCapture& Instance() {
        static ScreenshotCapture instance;
        return instance;
    }


    ~ScreenshotCapture() {
        DeleteObject(hbmScreen);
        DeleteDC(hdcMemDC);
        ReleaseDC(NULL, hdcWindow);
    }

    cv::Mat capture(std::vector<int>& region) {
        RECT rect;
        GetClientRect(hwnd, &rect);
        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;

        PrintWindow(hwnd, hdcMemDC, PW_CLIENTONLY); 

        BITMAPINFO bmi = { 0 };
        bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bmi.bmiHeader.biWidth = width;
        bmi.bmiHeader.biHeight = -height; 
        bmi.bmiHeader.biPlanes = 1;
        bmi.bmiHeader.biBitCount = 32; 
        bmi.bmiHeader.biCompression = BI_RGB;

        cv::Mat mat(height, width, CV_8UC4); 
        GetDIBits(hdcMemDC, hbmScreen, 0, height, mat.data, &bmi, DIB_RGB_COLORS);

        if (region.size() != 0) {
            int left = region[0];
            int top = region[1];
            int right = region[2];
            int bottom = region[3];
            if (left < 0 || top < 0 || right > width || bottom > height) {
                std::cout << "Region out of bounds" << std::endl;
                return cv::Mat();
            }
            cv::Rect roi(left, top, right - left, bottom - top);
            cv::Mat croppedMat = mat(roi);
            cv::Mat resultMat;
            cv::cvtColor(croppedMat, resultMat, cv::COLOR_BGRA2BGR);
            return resultMat;
        }
   
        cv::Mat resultMat;
        cv::cvtColor(mat, resultMat, cv::COLOR_BGRA2BGR);
        return resultMat;
    }
};


static std::vector<cv::Mat> blueCubePotential() {
    int left = 600 + 2;
    int right = 760;
    int top = 423;
    int bottom = 466;
    std::vector<int> region {left, top, right, bottom};
    ScreenshotCapture& capture = ScreenshotCapture::Instance();
    cv::Mat potential = capture.capture(region);

    int interval = (bottom - top) / 3;
    cv::Mat line1 = potential(cv::Rect(0, 0, potential.cols, interval - 3)).clone();
    cv::Mat line2 = potential(cv::Rect(0, interval, potential.cols, interval - 1)).clone();
    cv::Mat line3 = potential(cv::Rect(0, interval * 2, potential.cols, potential.rows - interval * 2)).clone();

    return std::vector<cv::Mat>{line1, line2, line3};
}

static std::vector<cv::Mat> redCubePotential() {
    int left = 600 + 2;
    int right = 760;
    int top = 478 + 3;
    int bottom = 521;
    std::vector<int> region {left, top, right, bottom};
    ScreenshotCapture& capture = ScreenshotCapture::Instance();
    cv::Mat potential = capture.capture(region);


    int interval = (bottom - top) / 3;
    cv::Mat line1 = potential(cv::Rect(0, 0, potential.cols, interval)).clone();
    cv::Mat line2 = potential(cv::Rect(0, interval, potential.cols, interval)).clone();
    cv::Mat line3 = potential(cv::Rect(0, interval * 2, potential.cols, potential.rows - interval * 2)).clone();

    return std::vector<cv::Mat>{line1, line2, line3};
}


static std::vector<cv::Mat> blackFlame() {
    int plus = 103;
    int left = 600 + 2;
    int right = 730;
    int top = 367 + plus;
    int bottom = 534 + plus;

    // Define the region of interest
    std::vector<int> region{ left, top, right, bottom };
    ScreenshotCapture& capture = ScreenshotCapture::Instance();
    cv::Mat flame = capture.capture(region);

    int ma = 5;
    int interval = 9;

    // Extracting lines
    cv::Mat line1 = flame(cv::Rect(0, 0, flame.cols, interval));
    cv::Mat line2 = flame(cv::Rect(0, interval + ma, flame.cols, interval));
    cv::Mat line3 = flame(cv::Rect(0, interval * 2 + 2 * ma, flame.cols, interval));
    cv::Mat line4 = flame(cv::Rect(0, interval * 3 + ma * 3, flame.cols, interval));
    cv::Mat line5 = flame(cv::Rect(0, interval * 4 + ma * 4, flame.cols, interval));
    cv::Mat line6 = flame(cv::Rect(0, interval * 5 + ma * 5, flame.cols, interval));

    return std::vector<cv::Mat>{line1, line2, line3, line4, line5, line6};
}


// rebirth flame
std::unordered_map<std::string, std::pair<std::string, int>> flameImageHub = {
    {"boss", {"flame/boss.png", 30}},
    {"att", {"flame/att.png", 30}},
    {"matt", {"flame/matt.png", 30}},
    {"dex", {"flame/dex.png", 30}},
    {"str", {"flame/str.png", 30}},
    {"int", {"flame/int.png", 30}},
    {"luk", {"flame/luk.png", 30}},
    {"all", {"flame/all.png", 50}},
    {"hp", {"flame/hp.png", 50}},
    {"dmg", {"flame/dmg.png", 50}}
};


std::unordered_map<std::string, std::pair<std::string, int>> imageHub = {
    {"boss", {"potential/boss.png", 30}},
    {"crtdmg", {"potential/criticaldmg.png", 70}},
    {"ignore", {"potential/ignore.png", 50}},
    {"cd", {"potential/cd.png", 70}},
    {"att", {"potential/att.png", 30}},
    {"matt", {"potential/matt.png", 30}},
    {"dex", {"potential/dex.png", 30}},
    {"str", {"potential/str.png", 30}},
    {"int", {"potential/int.png", 30}},
    {"luk", {"potential/luk.png", 30}},
    {"all", {"potential/all.png", 50}},
    {"hp", {"potential/hp.png", 50}},
    {"drop", {"potential/drop.png", 50}},
    {"meso", {"potential/meso.png", 50}},
    {"dmg", {"potential/dmg.png", 50}}
};

std::unordered_map<std::string, cv::Mat> LoadedHub;


static void load_hub(bool flame) {
    std::unordered_map<std::string, std::pair<std::string, int>>& images = imageHub;
    if (flame) {
        images = flameImageHub;
    }
    for (const auto& pair : images) {
        const std::string& key = pair.first;
        const std::string& path = pair.second.first;
        int width = pair.second.second;

        cv::Mat im = cv::imread(path, cv::IMREAD_UNCHANGED);
        if (im.empty()) {
            std::cerr << "Error loading image: " << path << std::endl;
            continue;
        }

        LoadedHub[key] = im(cv::Rect(0, 0, width, im.rows));  // Crop the image to the specified width
    }
}

static bool img_match(const cv::Mat& templateImg, const cv::Mat& im) {
    cv::Mat result;
    cv::matchTemplate(im, templateImg, result, cv::TM_CCOEFF_NORMED);

    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

    maxVal = round(maxVal * 100.0) / 100.0;  // Round to 2 decimal places
    double threshold = 0.93;
    if (maxVal >= threshold && (maxLoc.x + maxLoc.y) < 5) {
        return true;
    }

    return false;
}

static std::string img2text(const cv::Mat& im) {
    for (const auto& pair : LoadedHub) {
        const std::string& k = pair.first;
        const cv::Mat& templateImg = pair.second;

        if (img_match(templateImg, im)) {
            return k;
        }
    }
    return "unknown";
}


static void rollRedCude() {
    leftclick(697, 604);
    pressEnter();
    pressEnter();
    pressEnter();
    pressEnter();
    msleep(2000);
}

static void rollBlueCude() {
    leftclick(676, 539);
    pressEnter();
    pressEnter();
    pressEnter();
    msleep(2000);
}

static void rollBlackRebirthFlame() {
    leftclick(683, 633);
    msleep(200);
    pressEnter();
    msleep(200);
    pressEnter();
    msleep(200);
    pressEnter();
    msleep(2000);
}

static void matchFlame(int times, const std::vector<Rule>& groups) {
    for (int i = 0; i < times; ++i) {
        // got new lines 
        std::vector<cv::Mat> lines = blackFlame();
        std::vector<std::string> texts;

        // Convert images to texts
        for (const auto& line : lines) {
            texts.push_back(img2text(line));
        }

        // Filter out "unknown" texts
        texts.erase(std::remove(texts.begin(), texts.end(), "unknown"), texts.end());

        // merge the texts;
        std::string str;
        for (auto& text : texts) {
            str += text;
            str += "\t";
        }

        printf("[%d/%d]: %s\n", i + 1, times, str.c_str());


        // Iterate through each group
        for (const auto& group : groups) {
            int hit = group.hit;
            const std::vector<std::string>& keys = group.key;
            int count = 0;

            for (const std::string& text : texts) {
                if (std::find(keys.begin(), keys.end(), text) != keys.end()) {
                    count++;
                }
            }

            if (count >= hit) {
                std::cout << "match! ";
                for (const auto& key : keys) {
                    std::cout << key << " ";
                }
                std::cout << std::endl;
                return;
            }
        }

        // Call reset function
        rollBlackRebirthFlame();
    }

}


static void match(int times, const std::vector<Rule>& groups, bool is_red = false) {
    auto potential = is_red ? redCubePotential : blueCubePotential;  
    auto reroll = is_red ? rollRedCude : rollBlueCude;

    for (int i = 0; i < times; ++i) {
        // got new lines 
        std::vector<cv::Mat> lines = potential();
        std::vector<std::string> texts;

        // Convert images to texts
        for (const auto& line : lines) {
            texts.push_back(img2text(line));
        }

        printf("[%d/%d]: %s, %s, %s\n", i+1, times, texts[0].c_str(), texts[1].c_str(), texts[2].c_str());

        // Filter out "unknown" texts
        texts.erase(std::remove(texts.begin(), texts.end(), "unknown"), texts.end());

        // Iterate through each group
        for (const auto& group : groups) {
            int hit = group.hit;
            const std::vector<std::string>& keys = group.key;
            int count = 0;

            for (const std::string& text : texts) {
                if (std::find(keys.begin(), keys.end(), text) != keys.end()) {
                    count++;
                }
            }

            if (count >= hit) {
                std::cout << "match! ";
                for (const auto& key : keys) {
                    std::cout << key << " ";
                }
                std::cout << std::endl;
                return;
            }
        }

        // Call reset function
        reroll();
    }
}

void helpinfo() {
    printf("Usage: \n");
    printf("coffeestory [red/blue] [times] [target] \n");
    printf("coffeestory flame [times] [target] \n");
}


int main(int argc, char* argv[]) {
    if (argc == 1) {
        helpinfo();
        return 0;
    }
    reset_maple();
    std::string kind = argv[1];

    bool flame = false;
    bool is_red = false;
    if (kind == "red") {
        is_red = true;
        load_hub(false);
    }
    else if (kind == "blue") {
        is_red = false;
        load_hub(false);
    }
    else if (kind == "flame") {
        flame = true;
        load_hub(true);
    }
    else {
        helpinfo();
        return 0;
    }

    // Load the image hub
    int times = std::stoi(argv[2]);
    std::string target = argv[3];
    if (!flame) {
        if (auto p = Rules.find(target); p != Rules.end()) {
            match(times, p->second, is_red);
        }
        else {
            std::cout << "target not found! " << target << std::endl;
        }
    }
    else {
        if (auto p = FlameRules.find(target); p != FlameRules.end()) {
            matchFlame(times, p->second);
        }
        else {
            std::cout << "target not found! " << target << std::endl;
        }
    }

    return 0;
}
