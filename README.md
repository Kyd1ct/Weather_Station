# Weather Station
Arduino weather station assignment for CMP101 Computer Hardware Architectures and Operating Systems

Required parts:

Wemos D1 board </br>
DS3231 RTC </br>
TM1638 Module </br>
SSD1306 OLED 0.96" display </br>
Resistors</br>
LEDs</br>

The code allows your arduino to obtain data from OpenWeatherMap.org through their free API. The data is parsed onto a Json object then assigned to different variables for easier manipulation. </br>

The kit will display different data based on the parsed weather forecast. Additionally, the PNG files within the repository were converted into bitmaps with Marlin Bitmap Converter and displayed as graphics based on the weather - cloudy, sparse clouds, rain, thunder, mist, snow and clear weather (sunny). The temperature will also be displayed beside the graphics. The light of the clear LED will also change depending on the weather, while the yellow LED will work when the weather is clear. The screen will then switch and display the town's name, humidity and atmospheric pressure. 

The data is updated through the API every 10 minutes.
