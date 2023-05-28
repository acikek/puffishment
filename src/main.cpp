#include <Geode/Geode.hpp>

#include "modify/PlayerObjectMod.cpp"
#include "modify/PlayLayerMod.cpp"
#include "modify/EndLevelLayerMod.cpp"

using namespace geode::prelude;

$on_mod(Loaded) {
    log::info("Puffishment!");
}
