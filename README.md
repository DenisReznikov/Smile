[![Build status](https://ci.appveyor.com/api/projects/status/c6oyyokjn0ffn8n5/branch/master?svg=true)](https://ci.appveyor.com/project/DenisReznikov/smile/branch/master)
# Smile
![1463472544_7](https://user-images.githubusercontent.com/52967686/62469134-53cb6600-b7a0-11e9-832f-6645c97f96ad.gif)
## About
My task in the project consisted in rewriting the application in a new graphical framework(QT framework).
![KPboOSaQTy](https://user-images.githubusercontent.com/52967686/62468838-b112e780-b79f-11e9-9fac-bc363f8b70c0.gif)
### Application architecture
The application is divided into three main parts - GUI, business logic and server part. Plus there is a separate part - unit tests.
```
Smile/
├── Smile/
|   ├── GUI/                       // GUI & slightly business logic
|   ├── Server/                    // Data tier
├── Tests/                         // Unit test
```
