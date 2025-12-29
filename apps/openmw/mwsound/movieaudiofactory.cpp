#include "movieaudiofactory.hpp"

// FIX VITA: Archivo anulado.
// La implementación real requiere FFmpeg, que no tenemos.
// Dejamos el archivo vacío (salvo el include propio) para satisfacer a CMake.

#ifndef __vita__
// Aquí iría el código original...
namespace MWSound
{
    Video::AudioSink* MovieAudioFactory::createAudioSink(Video::AudioStream* stream)
    {
        return nullptr; // Placeholder del código original
    }
}
#endif
