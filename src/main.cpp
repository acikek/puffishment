#include <Geode/Geode.hpp>

#include "modify/PlayerObjectMod.cpp"
#include "modify/PlayLayerMod.cpp"

using namespace geode::prelude;

$on_mod(Loaded) {
    log::info("Puffishment!");
}