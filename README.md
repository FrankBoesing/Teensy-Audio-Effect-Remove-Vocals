# Teensy-Audio-Effect-Remove-Vocals

https://forum.pjrc.com/threads/33215-Effect-Remove-Vocals-aka-quot-Karaoke-quot


Some songs work good, others not. For a good effect, the vocals must be in the mid of both stereo-channels.

How does it work ?

Simple. It inverts the right channel and adds it to the left (the result is one mono channel).

I added a enable(bool) function which enables or disables the effect.
That means, if you disable it, you can use the effect as a simple way to transform stereo to mono.
