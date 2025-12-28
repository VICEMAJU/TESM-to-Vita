#include "videowidget.hpp"

// --- FIX VITA: Desactivar sistema de video (FFmpeg) ---
// En lugar de incluir la librería real, definimos una clase falsa (Stub)
// para satisfacer al compilador y al unique_ptr.

#include <MyGUI_RenderManager.h>
#include <osg/Texture2D>
#include <components/debug/debuglog.hpp>
#include <components/myguiplatform/myguitexture.hpp>
#include <components/vfs/manager.hpp>

// Falsificamos la clase VideoPlayer y el namespace Video
// Esto es necesario porque el header videowidget.hpp tiene un miembro de este tipo.
namespace Video
{
    class VideoPlayer
    {
    public:
        VideoPlayer() {}
        ~VideoPlayer() {}
        // No necesitamos implementar nada más porque no llamaremos a sus métodos.
    };
}

namespace MWGui
{

    VideoWidget::VideoWidget()
        : mVFS(nullptr)
    {
        // NO instanciamos el reproductor real.
        // Dejamos mPlayer como nullptr o creamos el dummy si fuera necesario,
        // pero como vamos a bloquear las llamadas, nullptr es seguro.
        // mPlayer = std::make_unique<Video::VideoPlayer>(); 
        setNeedKeyFocus(true);
    }

    // El destructor necesita ver la definición completa de VideoPlayer (nuestra falsa)
    VideoWidget::~VideoWidget() = default;

    void VideoWidget::setVFS(const VFS::Manager* vfs)
    {
        mVFS = vfs;
    }

    void VideoWidget::playVideo(const std::string& video)
    {
        // En Vita, simplemente ignoramos la petición de reproducir video.
        // Esto evitará crashes y dependencias de ffmpeg.
        Log(Debug::Info) << "PS Vita: Video playback skipped for " << video;
        
        // Opcional: Podrías poner una textura negra o estática aquí si quisieras,
        // pero dejarlo vacío simplemente mostrará lo que haya detrás (probablemente negro).
    }

    int VideoWidget::getVideoWidth()
    {
        return 0; // Sin video, sin ancho
    }

    int VideoWidget::getVideoHeight()
    {
        return 0; // Sin video, sin alto
    }

    bool VideoWidget::update()
    {
        // Devolver false indica que el video "ha terminado".
        // Esto es perfecto para saltar intros automáticamente.
        return false; 
    }

    void VideoWidget::stop()
    {
        // Nada que detener
    }

    void VideoWidget::pause()
    {
        // Nada que pausar
    }

    void VideoWidget::resume()
    {
        // Nada que reanudar
    }

    bool VideoWidget::isPaused() const
    {
        return false;
    }

    bool VideoWidget::hasAudioStream()
    {
        return false;
    }

    void VideoWidget::autoResize(bool stretch)
    {
        // Versión simplificada de autoResize que llena la pantalla
        // o hace lo básico para evitar cálculos con dimensiones 0.
        MyGUI::IntSize screenSize = MyGUI::RenderManager::getInstance().getViewSize();
        if (getParent())
            screenSize = getParent()->getSize();

        setCoord(0, 0, screenSize.width, screenSize.height);
    }

}
// -----------------------------------------------------
