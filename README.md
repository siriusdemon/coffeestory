# coffeestory
Reroll your potential while enjoying a cup of coffee.




This tool is designed to streamline the process of rerolling equipment potential in MapleStory. By capturing in-game screenshots and detecting potential lines using pattern matching, it helps players efficiently roll for desired stats. The tool automates the manual clicking process but does not include any auto-farming or botting features. Additionally, it can be used to analyze potential roll rates, providing valuable insights into the game's RNG mechanics.

However, I am not certain whether Nexon will classify this as a prohibited program. Use it at your own risk.



### Building

+ Visual Studio 2022 toolchains
+ Opencv


### Usage
Make sure your maplestory resolution is `1366x768`, or it may not work as expected.

```bash
coffeestory.exe [red/blue] [times] [target]
# e.g. for a 3 Att weapon
coffeestory.exe blue 1000 att3
```

[Demo on Youtube](https://youtu.be/jwFR9YFj2WY)


There are predefined targets for convenience. You can modify the coffeestory.h to add your own one.

### normal
|target name  |  meaning									|
|-------------|---------------------------------------------|
| int2		  | 2 lines of int/all							|
| int3		  | 3 lines of int/all							|
| luk2		  | 2 lines of luk/all							|
| luk3		  | 3 lines of luk/all							|
| dex2		  | 2 lines of dex/all							|
| dex3		  | 3 lines of dex/all							|
| str2		  | 2 lines of str/all							|
| str3		  | 3 lines of str/all							|
| hp2		  | 2 lines of hp								|
| hp3		  | 3 lines of hp								|
| all2		  | 2 lines of all								|
| all3		  | 3 lines of all								|

### weapon

|target name  |  meaning									|
|-------------|---------------------------------------------|
| att3		  | 3 lines of Attack							|
| att2		  | 2 lines of Attack						|
| matt3		  | 3 lines of Magic Attack						|
| matt2		  | 2 lines of Magic Attack						|
| attb		  | 3 lines of Attack/Boss						|
| mattb		  | 3 lines of Magic Attack/Boss				|
| arm3		  | 3 lines of Attack/Boss/damage/ignore		|
| arm2		  | 2 lines of Attack/Boss/damage/ignore		|
| marm3		  | 3 lines of Magic Attack/Boss/damage/ignore	|
| marm2		  | 2 lines of Magic Attack/Boss/damage/ignore	|



### glove
|target name  |  meaning									|
|-------------|---------------------------------------------|
| crtdmg1	  | 1 line  of critical damage					|
| crtdmg2	  | 2 lines of critical damage					|
| crtdmg3	  | 3 lines of critical damage					|
| lukcrtdmg2  | 2 lines of critical damage/luk/all			|
| lukcrtdmg3  | 3 lines of critical damage/luk/all			|
| strcrtdmg2  | 2 lines of critical damage/str/all			|
| strcrtdmg3  | 3 lines of critical damage/str/all			|
| dexcrtdmg2  | 2 lines of critical damage/dex/all			|
| dexcrtdmg3  | 3 lines of critical damage/dex/all			|
| intcrtdmg2  | 2 lines of critical damage/int/all			|
| intcrtdmg3  | 3 lines of critical damage/int/all			|
| allcrtdmg2  | 2 lines of critical damage/all				|
| allcrtdmg3  | 3 lines of critical damage/all				|
| hpcrtdmg2   | 2 lines of critical damage/hp				|
| hpcrtdmg3   | 3 lines of critical damage/hp				|


### cd hat
|target name  |  meaning									|
|-------------|---------------------------------------------|
| cd1		  | 1 line  of skill cooldown					|
| cd2		  | 2 lines of skill cooldown					|
| cd3		  | 3 lines of skill cooldown					|
| lukcd2	  | 2 lines of skill cooldown/luk				|
| lukcd3	  | 3 lines of skill cooldown/luk				|
| dexcd2	  | 2 lines of skill cooldown/dex				|
| dexcd3	  | 3 lines of skill cooldown/dex				|
| strcd2	  | 2 lines of skill cooldown/str				|
| strcd3	  | 3 lines of skill cooldown/str				|
| intcd2	  | 2 lines of skill cooldown/int				|
| intcd3	  | 3 lines of skill cooldown/int				|
| allcd2	  | 2 lines of skill cooldown/all				|
| allcd3	  | 3 lines of skill cooldown/all				|
| hpcd2	      | 2 lines of skill cooldown/hp				|
| hpcd3	      | 3 lines of skill cooldown/hp				|


### accessory

|target name  |  meaning											|
|-------------|-----------------------------------------------------|
| md1		  | 1 line  of meso/drop								|
| md2		  | 2 lines of meso/drop								|
| md3		  | 3 lines of meso/drop								|
| d1		  | 1 line  of drop										|
| d2		  | 2 lines of drop										|
| d3		  | 3 lines of drop										|
| lukmd2	  | 2 lines of meso/drop/luk/all						|
| intmd2	  | 2 lines of meso/drop/int/all						|
| strmd2	  | 2 lines of meso/drop/str/all						|
| dexmd2	  | 2 lines of meso/drop/dex/all						|
| allmd2	  | 2 lines of meso/drop/all							|
| hpmd2		  | 2 lines of meso/drop/all							|
| intmd3      | 3 lines of meso/drop/int/all or 2 lines of meso/drop|
| strmd3      | 3 lines of meso/drop/str/all or 2 lines of meso/drop|
| dexmd3      | 3 lines of meso/drop/dex/all or 2 lines of meso/drop|
| allmd3      | 3 lines of meso/drop/all	 or 2 lines of meso/drop|
| lukmd3      | 3 lines of meso/drop/luk/all or 2 lines of meso/drop|
| hpmd3       | 3 lines of meso/drop/all	 or 2 lines of meso/drop|
