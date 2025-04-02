#include "SFXManager.h"

SFXManager* SFXManager::instance = nullptr;

SFXManager::SFXManager() {}

SFXManager* SFXManager::getInstance() {
    if (!instance) {
        instance = new SFXManager();
    }
    return instance;
}

void SFXManager::loadAll()
{
    loadSound("background", "Media/Sounds/background.wav");
    loadSound("death", "Media/Sounds/death.wav");
    loadSound("walking2", "Media/Sounds/walking2.wav");
    loadSound("win1", "Media/Sounds/win1.wav");
    loadSound("win2", "Media/Sounds/win2.wav");
    loadSound("winner", "Media/Sounds/winner.wav");
}

void SFXManager::loadSound(const std::string& key, const std::string& filename) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filename)) {
        std::cout << "Failed to load sound file: " << filename << std::endl;
        return;
    }
    buffers[key] = buffer;
    sf::Sound sound;
    sound.setBuffer(buffers[key]);
    sounds[key] = sound;
}

void SFXManager::playSound(const std::string& key) {
    if (sounds.find(key) != sounds.end()) {
        sounds[key].play();
    }
    else {
        std::cout << "Sound not found: " << key << std::endl;
    }
}

SFXManager::~SFXManager() {
    delete instance;
}
