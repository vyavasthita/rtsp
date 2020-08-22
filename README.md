# rtsp
RTSP Server And Client

RTSP Server is written in gstreamer1.0.

RTSP Client is written in QT5 along with Qt5Gstreamer binding.
Qt uses gstreamer as a media service (backend).

# OS : Lubuntu

# RTSP Server
	Step 1 : Install Gstreamer packages
		
		sudo apt-get install libgstreamer1.0-0 gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio
		
		# Test gstreamer
			After installation of all above packages, test if gstreamer installation is successfull by running below command.
			You will get some text output on sucess.
			
				gst-launch-1.0 -v fakesrc num_buffers=5 ! fakesink
		
		# Qt Binding
		sudo apt-get install qtmultimedia5-dev
		sudo apt-get install libqt5gstreamer-dev
		sudo apt-get install libgstreamer1.0-dev
		sudo apt-get install gstreamer1.0-rtsp
		sudo apt-get install libgstrtspserver-1.0-dev
		
		# While building using QtCreator
			Error => Qt5GStreamer-1.0 development package not found
			Solution => LIBS += -lQt5GStreamer-1.0 -lQt5GStreamerUi-1.0
		
		# While running using QtCreator
			Error => defaultServiceProvider::requestService no service found for org.qt-project.qt.mediaplayer
			Solution => sudo apt-get install libqt5multimedia5-plugins

	Step 2 : Compile
		gcc <file>.c -o <executable> $(pkg-config --cflags --libs gstreamer-1.0 gstreamer-rtsp-server-1.0)


# RTSP Client
	Create a QMainWindow project
	And run.
	Use similar url for viewing the video => rtsp://<IP>:8554/server

# ---------------------------------------------------------------------------------
# Source Code
	# gstreamer => https://gitlab.freedesktop.org/gstreamer/gst-build
	# Qt gstreamer => https://github.com/GStreamer/qt-gstreamer
	
# References
	https://gstreamer.freedesktop.org/data/doc/gstreamer/head/qt-gstreamer/html/index.html
	https://gstreamer.freedesktop.org/bindings/qt.html
	https://github.com/b2open/qt-rtsp-test
