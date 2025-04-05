#pragma once
#include "SFML/Audio.hpp"
#include <iostream>
#include <map>
#include <string>

class SFXManager {
private:
    static SFXManager* instance;
    std::map<std::string, sf::SoundBuffer> buffers;
    std::map<std::string, sf::Sound> sounds;

    SFXManager();

public:
    static SFXManager* getInstance();
    void loadAll();
    void loadSound(const std::string& key, const std::string& filename);
    void playSound(const std::string& key);

    void stopPlaying(const std::string& key);
    bool isPlaying(const std::string& key);

    ~SFXManager();
};