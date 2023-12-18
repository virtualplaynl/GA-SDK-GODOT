#!/bin/sh

scons arch=universal ios_simulator=yes platform=ios target=$1 $2
scons arch=arm64 ios_simulator=no platform=ios target=$1 $2

xcodebuild -create-xcframework -library ./lib/libgameanalytics.ios.$1.a -library ./lib/libgameanalytics.ios.$1.simulator.a -output ./lib/libgameanalytics.ios.$1.xcframework
xcodebuild -create-xcframework -library ./godot-cpp/bin/libgodot-cpp.ios.$1.arm64.a -library ./godot-cpp/bin/libgodot-cpp.ios.$1.universal.simulator.a  -output ./lib/libgodot-cpp.ios.$1.xcframework
