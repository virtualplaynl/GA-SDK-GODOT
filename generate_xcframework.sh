#!/bin/sh

scons ios_simulator=yes platform=ios disable_exceptions=false target=$1 $2
scons platform=ios disable_exceptions=false target=$1 $2

rm -rf ./lib/libgameanalytics.ios.$1.xcframework
rm -rf ./lib/libgodot-cpp.ios.$1.xcframework
xcodebuild -create-xcframework -library ./lib/libgameanalytics.ios.$1.a -library ./lib/libgameanalytics.ios.$1.simulator.a -output ./lib/libgameanalytics.ios.$1.xcframework
xcodebuild -create-xcframework -library ./godot-cpp/bin/libgodot-cpp.ios.$1.arm64.a -library ./godot-cpp/bin/libgodot-cpp.ios.$1.universal.simulator.a  -output ./lib/libgodot-cpp.ios.$1.xcframework

rm -rf ./example/lib/ios/libgameanalytics.ios.$1.xcframework
rm -rf ./example/lib/ios/libgodot-cpp.ios.$1.xcframework
cp -r ./lib/libgameanalytics.ios.$1.xcframework ./example/lib/ios
cp -r ./lib/libgodot-cpp.ios.$1.xcframework ./example/lib/ios
