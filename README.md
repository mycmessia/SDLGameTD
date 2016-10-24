# SDLGameTD
This is a tower defense game based on SDL and a good way to know the basic principles of 2D game engine.<br />

In this project, I implemented command pattern to handle the inputs making it easy to change the commands of different buttons.<br />

State pattern is used to build the player and enemy AI systems.<br />

The project is created by XCode so it is better to see it by that.<br />

There are also some XCode groups in the project which classify these files.<br />

Also I put the four SDL frameworks used in this project in a separate folder so you do not need to find them anywhere else.<br />

If you are using a mac, just make sure you copy all the frameworks into the /Library/Frameworks folder.<br />

Another thing is I use relative directory to link the resources like images and fonts, so if your project reports an error said they can not find resources, you need to change the working directory as shown by the followed image.<br />
You can find this window by Product->Scheme->Edit Scheme<br /><br />
![] (https://github.com/mycmessia/SDLGameTD/blob/master/change_working_directory.png)<br /><br />

Here is a screen shot of this game and hope you are interested in it.<br />
![] (https://github.com/mycmessia/SDLGameTD/blob/master/SDLGameTD/resources/screen_shot.png)
