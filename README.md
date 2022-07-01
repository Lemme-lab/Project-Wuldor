# Project Wuldor
---
## A completely custom 6 Axis Roboter-Arm (Still in progress) that won the 2022 HTL Mössingerstraße Technicus Award. 
---
![Logo](https://user-images.githubusercontent.com/71924682/163667757-7f6cb828-fb65-4eb2-ae69-8ef3ffe92f84.png)
---
![Banner](https://user-images.githubusercontent.com/71924682/163182237-645129a7-b3d2-4f1d-b3c3-a3557a9aed62.png)
---
![unnamed](https://user-images.githubusercontent.com/71924682/174161704-4a6a0930-17b0-4eb0-8d15-6856ae47b7ed.jpg)
---
![Packaging_Arm](https://user-images.githubusercontent.com/71924682/176860059-a872393a-3037-409e-b3f2-3a51f8c3f57b.png)
---
![Packaging_PCB's](https://user-images.githubusercontent.com/71924682/176860047-57b8fb82-48d8-4175-89a1-5a985d61803a.png)
---
![20220630_121323](https://user-images.githubusercontent.com/71924682/176860115-f045ef31-d4b3-4335-a10a-a1e75737de9a.jpg)
---
![PCB-Display](https://user-images.githubusercontent.com/71924682/176549191-eafeca05-2f2f-4f0e-ad06-6beeb9baefd2.png)

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
![Main_PCB_Renders](https://user-images.githubusercontent.com/71924682/163667769-41ce03c1-6c7b-4661-8a2b-bfcb614f81bc.png)
---
![Stepper_motors_driver_renders](https://user-images.githubusercontent.com/71924682/163667771-07915689-6b87-48ac-b06e-d02059a8ad2e.png)
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
 ![Website-Wuldor](https://user-images.githubusercontent.com/71924682/174283243-d87d0f66-6094-4267-964e-426b13ef7c48.png)
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
  ![App-Prototype](https://user-images.githubusercontent.com/71924682/174283200-e9082e55-8ff7-4b68-a1ac-c82ccfe6f026.png)
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
![IN_WORK](https://user-images.githubusercontent.com/71924682/164968803-e9cef057-9668-4230-84af-13a69991e0e7.png)
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
![Pr_1](https://user-images.githubusercontent.com/71924682/174161553-aae333e0-0505-49c0-9cf9-d45af9523c51.png)
---
![Pr_2](https://user-images.githubusercontent.com/71924682/174161582-c9f3f4b6-53cf-43e1-b05f-80f3a960bc51.png)
---
![Pr_3](https://user-images.githubusercontent.com/71924682/174161590-ae99e1b9-a07f-4817-bb78-bb09a03a54bb.png)
---
![Pr_4](https://user-images.githubusercontent.com/71924682/174161601-31ec4d24-b536-4ecf-b792-09307122cfae.png)
---
![Pr_5](https://user-images.githubusercontent.com/71924682/174161614-79b28936-628b-4247-852c-29107661b0a6.png)
---



------

