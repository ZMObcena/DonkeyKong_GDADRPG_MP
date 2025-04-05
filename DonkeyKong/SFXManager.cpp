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
    loadSound("intro", "Media/Sounds/intro.wav");
    loadSound("death", "Media/Sounds/death.wav");
    loadSound("walking2", "Media/Sounds/walking2.wav");
    loadSound("win1", "Media/Sounds/win1.wav");
    loadSound("win2", "Media/Sounds/win2.wav");
    loadSound("winner", "Media/Sounds/winner.wav");
    loadSound("results", "Media/Sounds/howhigh.wav");
    loadSound("item", "Media/Sounds/itemget.wav");
    loadSound("jump", "Media/Sounds/jump.wav");
    loadSound("point", "Media/Sounds/point.wav");
    loadSound("press", "Media/Sounds/press.wav");
    loadSound("clear", "Media/Sounds/clear.wav");
}

void SFXManager::loadSound(const std::string& key, const std::string& filename) 
{
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

void SFXManager::playSound(const std::string& key) 
{
    std::string bg = "background";
    sounds[bg].setVolume(40);
    std::string wk = "walking2";
    sounds[wk].setVolume(40);
    std::string jm = "jump";
    sounds[jm].setVolume(5);
    std::string dt = "death";
    sounds[dt].setVolume(40);

    if (sounds.find(key) != sounds.end()) 
    {
        sounds[key].play();
    }
    else 
    {
        std::cout << "Sound not found: " << key << std::endl;
    }
}

void SFXManager::stopPlaying(const std::string& key)
{
    if (sounds.find(key) != sounds.end()) 
    {
        sounds[key].stop();
    }
    else 
    {
        std::cout << "Sound not found: " << key << std::endl;
    }
}

bool SFXManager::isPlaying(const std::string& key)
{
    if (sounds.find(key) != sounds.end())
    {
        return sounds[key].getStatus() == sf::Sound::Playing;
    }
    return false;
}

SFXManager::~SFXManager() {
    delete instance;
}
