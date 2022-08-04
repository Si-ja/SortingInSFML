#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H
#include <SFML/Audio.hpp>

class AudioPlayer
{
public:
	sf::SoundBuffer beepBuffer;
	std::string const beepLocation{ "Audio/Beep.wav" };
	sf::Sound beepSound;
	float soundPitch{ 1.0f };

	/// <summary>
	/// Construct a small audio player that can play sounds that we allow it to access.
	/// </summary>
	AudioPlayer();

	/// <summary>
	/// Play the beep noise.
	/// </summary>
	void playBeep();
};

#endif