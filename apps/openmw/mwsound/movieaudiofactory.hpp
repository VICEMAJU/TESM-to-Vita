#ifndef OPENMW_MWSOUND_MOVIEAUDIOFACTORY_HPP
#define OPENMW_MWSOUND_MOVIEAUDIOFACTORY_HPP

// FIX VITA: Stub para MovieAudioFactory.
// Desactivamos la dependencia real de osg-ffmpeg-videoplayer.

#ifndef __vita__
    // Si NO es Vita, intentamos incluir el archivo original (que fallará si no tienes ffmpeg)
    #include <osg-ffmpeg-videoplayer/audiofactory.hpp>

    namespace MWSound
    {
        class MovieAudioFactory : public Video::AudioFactory
        {
        public:
            virtual Video::AudioSink* createAudioSink(Video::AudioStream* stream);
        };
    }
#else
    // Si ES Vita, usamos una clase vacía para que el compilador no se queje si la ve.
    namespace MWSound
    {
        class MovieAudioFactory
        {
        public:
            // No hace nada, no hereda de nada.
        };
    }
#endif

#endif
