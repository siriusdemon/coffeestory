# coffeestory
Reroll your potential while enjoying a cup of coffee.




This tool is designed to streamline the process of rerolling equipment potential in MapleStory. By capturing in-game screenshots and detecting potential lines using pattern matching, it helps players efficiently roll for desired stats. The tool automates the manual clicking process but does not include any auto-farming or botting features. Additionally, it can be used to analyze potential roll rates, providing valuable insights into the game's RNG mechanics.

However, I am not certain whether Nexon will classify this as a prohibited program. Use it at your own risk.



### Building

+ Visual Studio 2022 toolchains
+ Opencv


### Usage
```bash
coffeestory.exe [red/blue] [times] [target]
# e.g. for a 3 Att weapon
coffeestory.exe blue 1000 att3
```

There are predefined targets for convenience. You can modify the coffeestory.h to add your own one.

|-target name-|-meaning-|
------------------------
| att3 | 3 lines of Attack|


