#include "AudioPlayer.h"
#include <SFML/Graphics.hpp>

AudioPlayer::AudioPlayer()
{
	this->beepBuffer.loadFromFile(this->beepLocation);
	this->beepSound.setBuffer(this->beepBuffer);
	this->beepSound.setPitch(this->soundPitch);
}

void AudioPlayer::playBeep()
{
	this->beepSound.play();
}
