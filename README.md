ck2launcher
===========

Custom Qt5 launcher for Crusader Kings 2 Game

## Dependencies

* **>=gcc-4.7.2** or **>=clang-3.3**
* **>=libboost-1.50**
* **Qt 5**

## How to install

```bash
mkdir build
cd build
cmake ..
make
sudo make install
```

## Run launcher with Steam
* Right click in **Crusader Kings II** under the **LIBRARY** tab
* Choose "Properties" option
* Click on button **SET LAUNCH OPTIONS...**
* Replace the current text with "ck2launcher %command%" (without the quotes)
* Play the game
