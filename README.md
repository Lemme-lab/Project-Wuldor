# Project Wuldor
---
## A completely custom 6 Axis Roboter-Arm (Still in progress) that won the 2022 HTL Mössingerstraße Technicus Award. 
---
![Logo](https://user-images.githubusercontent.com/71924682/176889683-ce06f6b1-4021-4f41-9f95-f9de0e4c8e2d.png)
---
![Banner](https://user-images.githubusercontent.com/71924682/163182237-645129a7-b3d2-4f1d-b3c3-a3557a9aed62.png)
---
![unnamed](https://user-images.githubusercontent.com/71924682/174161704-4a6a0930-17b0-4eb0-8d15-6856ae47b7ed.jpg)
---
![Packaging_Arm](https://user-images.githubusercontent.com/71924682/176889760-4fde1e47-e28a-4131-8343-0f1ae1778399.png)
---
![Packaging_PCB's](https://user-images.githubusercontent.com/71924682/176889770-3f93556b-0338-43da-88a1-d4b7408e873c.png)
---
![PCB-Display](https://user-images.githubusercontent.com/71924682/176889785-07e952ef-9fc3-4b2d-ae9f-c55c6f9ce349.png)
---
![20220630_121323](https://user-images.githubusercontent.com/71924682/176860115-f045ef31-d4b3-4335-a10a-a1e75737de9a.jpg)
---
![3D-Modell_2022-Mar-06_03-12-34PM-000_CustomizedView13790056020_mp4 (1)](https://user-images.githubusercontent.com/71924682/162983907-fc5d91c6-affc-4a69-b7b2-4bfbc3d428b0.gif)
---

## Features 
- Self Designed Stepper Motor Controller (A4988) 
- Self designed Main Controller with a small footprint
- Compact Size Factor
- Esthetic 
- Many other little Features

---
![Main_PCB_Renders](https://user-images.githubusercontent.com/71924682/176889810-2718931a-76b3-448d-b97d-be2a3cb72dbb.png)
---
![Stepper_motors_driver_renders](https://user-images.githubusercontent.com/71924682/176889823-f2102f27-e34e-4860-ab90-768e1afe88b0.png)
---

## Planned Code:
### General:  
A few bullet points and explanations for the code part. Different technologies and programming languages such as C++, WEB-Dev, and Flutter will be used. It will go from Basic C and register manipulation to UI-Development on Cross-Platform Mobile Apps.  
  
- Controlling Axis 1- 5  
- Save Control sequence  
- Remote  Connection  
- Desktop  Application  
- Website  
- Mobile App  
- PHP Database  
- C++, HTML, CSS, JS, FLUTTER, JAVA, Python
- Tensorflow, Keras

---
  
### Website:  
An HTML Website that must be functional and appealing to use. Features will be send via a ESP32 and the included Wireless module. Cross-platform Data will mean that we will have to save the current data and inputs on a small database. UI and other Features will mean that we have to use JS with or without an additional framework.  
 --- 
![Website-Wuldor](https://user-images.githubusercontent.com/71924682/176889860-0bb44c3b-7929-4867-9c0b-16012f84b507.png)
 --- 
- Checking Power Status  
- Check Wireless Connection  
- Current Voltage/Power Levels  
- Slider  Controlls for Motors  
- Test Motor func  
- Switch Mode (Normal Control, Train ,AI)  
- Cam Live Stream implementation  
- Stop/Start/hold -->pan> Slide buttons  
- Speed  
- Axis coordinates  
  
--- 
  
### Desktop Client  
A C++ or Java desktop client to be used when wired up to the robot arm. From the User ready interface to debbuging, testing and programming features will be included. This is one of the most important interface to the robot arm and as such it will be programmed first.  
  
- Checking Power Status  
- Check Wireless Connection  
- Current Voltage/Power Levels  
- Slider  Controlls for Motors  
- Test Motor func  
- Switch Mode (Normal Control,AI)  
- Cam  
- Debug Features / Console  
- Test  Features  
- Stop/Start/Hold -->  slidebuttons  
- Speed  
  
--- 
  
### Mobile Client  
Last we will do a Mobile Client app for controlling and checking the robot arm on the go. It will be programmed in Flutter or another Mobile Cross Platform Developer Kit.
--- 
  ![App-Prototype](https://user-images.githubusercontent.com/71924682/176889877-8fad88aa-a936-485a-b439-318b7f31bda3.png)
---   
- Checking Power Status  
- Check Wireless Connection  
- Current-Voltage/Power Levels  
- Settings  
- Live Cam   

---

### Self-Test
Testclasses to exclude code-mistakes. Motors are working in the corract way and also the remote connection and controlling from the web applicatio, if so then we can put everything together and test the whole thing

- Motor
- Remote Connection
- Connections Seriell/Connectors 
  
---
### Currently in Work
---
![IN_WORK](https://user-images.githubusercontent.com/71924682/176889892-48be1b40-b2a0-4fce-82e5-abb11356f14f.png)
---
The whole code will be versioned via GIT, inputs to the Roboter Arm tested, and the whole project will be publicly available on GitHub.
---
https://trello.com/b/jWCULnX8
---

## Stepper Motor + Reducer
![17HS4401 v4](https://user-images.githubusercontent.com/71924682/151709967-6a5edc47-0b74-4c29-b76b-47b9c884aeba.png)
---
![17HS15-1684S-HG100 v7](https://user-images.githubusercontent.com/71924682/151709971-32960aa0-3ec6-4480-b924-76f72bf15298.png)
---
![11HS20-0674S-PG51 v3](https://user-images.githubusercontent.com/71924682/152644415-916e31d6-8924-4a1c-a3fa-ed6c7dad81c9.png)


------

## Stepper Motor Controller 
![Screenshot_175](https://user-images.githubusercontent.com/71924682/156928832-3986db69-d386-4c26-937b-db4ccc1eadf6.png)
------
![Screenshot_176](https://user-images.githubusercontent.com/71924682/156928836-a2b7b5c8-ac6f-4433-93d5-e319139ed07f.png)
------
![Screenshot_177](https://user-images.githubusercontent.com/71924682/156928839-b26b0f5b-6ffd-4dd3-a89a-9f2da9806b8a.png)
------
![SteppperController pdf_v1_2022-Apr-15_08-58-34AM-000_CustomizedView13134334629_png_alpha](https://user-images.githubusercontent.com/71924682/174162245-e631b8e7-ae62-4040-aaf2-dbfd24276e2e.png)
![SteppperController pdf_v1_2022-Apr-15_08-48-39AM-000_CustomizedView932799733_png_alpha](https://user-images.githubusercontent.com/71924682/174162251-df7367cd-d6fa-46c1-97dd-e54b15fce040.png)
------

## Main Controller
![Screenshot_178](https://user-images.githubusercontent.com/71924682/156928879-2f2f591a-757a-42b8-84b4-ae6c8691ae27.png)
------
![Screenshot_179](https://user-images.githubusercontent.com/71924682/156928880-1687afad-905a-47e9-b161-ab6e3cdffd22.png)
------
![Main_Controller pdf_2022-Apr-15_07-07-20AM-000_CustomizedView21684845978_png_alpha](https://user-images.githubusercontent.com/71924682/174162310-4e199581-c6cd-4b50-a8a0-cfcd223b7416.png)
![Main_Controller pdf_2022-Apr-15_07-34-52AM-000_CustomizedView14152361556_png_alpha](https://user-images.githubusercontent.com/71924682/174162320-13b8f8e5-782d-496a-a555-3069ae9289a4.png)
------
![3D-Modell_2022-Jan-30_05-11-22PM-000_CustomizedView10729507097_png_alpha](https://user-images.githubusercontent.com/71924682/151709983-bdec6fbc-fdbe-4707-89a5-e2252b18024d.png)


------

## Roboter-Arm
---
![Assemlby Bottom](https://user-images.githubusercontent.com/71924682/176889947-20d4d246-dcba-47f3-84e0-ab89c786e5d7.png)
---
![Assembly Arm 2](https://user-images.githubusercontent.com/71924682/176889987-5a62f4df-7da8-40a1-b7aa-c573293a9f9f.png)
---
![Assembly Gripper](https://user-images.githubusercontent.com/71924682/176890013-187ed552-aec6-40ad-addf-8367c1671c65.png)
---
![View Arm 3-4-5](https://user-images.githubusercontent.com/71924682/176890022-76d7f0ce-6a86-46b0-9121-b29c366bc9a2.png)
---
![Assembly Led Ring - Base](https://user-images.githubusercontent.com/71924682/176890039-43e2691c-b131-4e55-801a-dbc21f5ad780.png)
---



------

