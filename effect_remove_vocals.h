/* "Remove Vocals" Effect for Teensy Audio Library 
 * Copyright (c) 2016, Frank Bösing, f.boesing@gmx.de
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, development funding notice, and this permission
 * notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#ifndef effect_RemoveVocals_h_
#define effect_RemoveVocals_h_
#include "AudioStream.h"
#include "utility/dspinst.h"

class AudioEffectRemoveVocals : public AudioStream
{
public:
	AudioEffectRemoveVocals() : AudioStream(2, inputQueueArray) { }	
	void enable(bool e) { e = enabled; }
	virtual void update(void);	
private:
	audio_block_t *inputQueueArray[2];
	bool enabled = true;
};

#endif
