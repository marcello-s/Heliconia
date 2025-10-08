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


Build Stuff
-----------

$ cmake -S. -Bbuild
$ cmake --build build --config Release --target heliconia --verbose

Libraries
---------
json, https://github.com/nlohmann/json
for cmake, https://json.nlohmann.me/integration/cmake/#external
$ git submodule add https://github.com/nlohmann/json.git libs/json
$ git submodule update --init --recursive

unit-tests catch2, https://github.com/catchorg/Catch2.git
for cmake, https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md
$ git submodule add https://github.com/catchorg/Catch2.git libs/catch2
$ git submodule update --init --recursive