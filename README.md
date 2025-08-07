<h2>Requirements</h2>
<pre>

== Libraries == <hr/>
libc++, libm, libSDL2, libSDL2_image, libSDL2_mixer, libSDL2_ttf

== Tools == <hr/>
make, g++
</pre>


<h2>Setup</h2>
<pre>

== Windows == <hr/>
-> Clone the repo (or download repo zip and extract it)
-> <u>mingw</u> compilers and <u>make</u> must be installed
-> From root folder of repo run <u>make</u> on command line
-> This should create a file <u>bin/game.exe</u>
-> Now, you can run <u>bin/game.exe</u>

== Linux/Unix based os ==<hr/>
-> Clone the repo
-> ensure <u>g++</u> and <u>make</u> are available
-> Install SDL2, SDL2_image, SDL2_mixer and SDL2_ttf
-> Libraries are installable from your package manager 
-> From root folder of repo run <u>make linux</u>
-> This should create a file <u>bin/game.out</u>
-> Now, you can run <u>bin/game.out</u>
</pre>