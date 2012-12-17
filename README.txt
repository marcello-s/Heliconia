HELICONIA
=========

This is a small homebrew project to monitor plants at your home.

The Idea
--------

After looking through a box full of electronics, a friend and I 
came up with the idea to run this little project about monitoring 
the level of water of plants and flower pots that are in your home. 
When the level is low, a message is texted, emailed, twittered.

The Stuff
---------

So we have a couple of electronics boards at our display:
* Arduino Diecimila
* Telit GM862-GPS-GSM
* Raspberry Pi Type-B

We want to connect them, so we can sense the water level, or 
conductivity, and then send out a message to whatever channel.
Some scripts and modules have to written. The idea is to re-use 
software modules that are available freely and write new ones. 
Some will be close to hardware maybe written in C/C++ other may 
be scripts to start up a GUI window and update some values in a 
text file.

The Project
-----------

This is the repository where we will exchange all information.
The name was primarily chosen because it was available, and hey it 
is a beautiful flower too.
