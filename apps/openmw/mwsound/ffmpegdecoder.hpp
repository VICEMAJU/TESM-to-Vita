#ifndef OPENMW_MWSOUND_FFMPEGDECODER_HPP
#define OPENMW_MWSOUND_FFMPEGDECODER_HPP

// FIX VITA: En PS Vita no usamos FFmpeg.
// Bloqueamos el contenido real para evitar errores de includes faltantes.

#ifndef __vita__

#include <string>
#include "sounddecoder.hpp"

// Aquí irían los includes de FFmpeg que causan el error.
// Al estar dentro del #ifndef __vita__, el compilador los ignora.

namespace MWSound
{
    class FFmpeg_Decoder : public SoundDecoder
    {
    public:
        FFmpeg_Decoder(const VFS::Path::NormalizedView& fname, const VFS::Manager* resourceMgr);
        virtual ~FFmpeg_Decoder();

        virtual void open(const std::string& fname);
        virtual void close();

        virtual std::string getName();
        virtual void getInfo(int* samplerate, ChannelConfig* chans, SampleType* type);

        virtual size_t read(char* buffer, size_t bytes);
        virtual void rewind();
        virtual bool isStream();
        virtual size_t getSampleRate();
        virtual ChannelConfig getChannelConfig();
        virtual SampleType getSampleType();
        virtual size_t getFrameSize();
        virtual size_t getSampleCount();
        virtual size_t getSampleOffset();

    private:
        struct Impl;
        std::unique_ptr<Impl> mImpl;
    };
}

#endif // Fin de ifndef __vita__

#endif // OPENMW_MWSOUND_FFMPEGDECODER_HPP
