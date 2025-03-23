# Overview

This project is a Shark Typer-like game, inspired by the song [Big Man Blastoise](https://www.youtube.com/watch?v=eY_DBWkwSC4)

Also a playground for me to practice Bazel, Github Actions and all sorts of undiscovered areas of development.

There will be further updates to this file once the project is near completion or at least reaches the MVP state

Until then enjoy this gif and feel free to dig through this little mess of a code base if you fancy checking out what I've done so far
![BigManBlastoiseGif](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fmedia.tenor.com%2FkMO13rsdbM0AAAAM%2Fblastoise-water.gif&f=1&nofb=1&ipt=80b8f51bebda57a1a6a9ec07692bd2eb1a6c5540f4e31df0e0eaea4d30304826&ipo=images)

# How to build it yourself
## Requirements:
- bazel 7.5.0


## How?
Assuming that you've got all the deps set up you need to run the following command
``bazel build //src:package``

That's it, then you can go to the output link that the console would log, or `bazel-bin/src/` and you'll find a file named package.zip
