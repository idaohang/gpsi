#ifndef INC_SPLASHPANEL_H
#define INC_SPLASHPANEL_H

/** \file
 * File for the Splash panels.
 *
 * @author Nathan Samson
*/

#include <string>
#include <queue>

#include "panels/sdlpanel.h"
#include "resources/resourcemanager.h"
#include "misc/stopwatch.h"
#include "misc/prefetcher.h"

namespace Zabbr {

	/**
	 * A Splash panel.
	 *
	 * @ingroup panels
	 *
	 * This will display a splash image and messages.
	*/
	class SplashPanel: public VSDLPanel {
	public:
		SplashPanel(SDLWindow*, std::string, VSDLPanel*);
		virtual ~SplashPanel();
		void addPrefetcher(IPrefetcher*);

		virtual void draw();
	private:
		class EmptyPrefetcher: public IPrefetcher {
		public:
			virtual ~EmptyPrefetcher();
			
			virtual bool operator()();
			virtual std::string name();
		};
	
		/**
		 * The splash image.
		*/
		ImageResource* fImage;
		
		/**
		 * The panel that should be loaded after loading is done.
		*/
		VSDLPanel* fNextPanel;
		
		/**
		 * Prefetcher list.
		*/
		std::queue<IPrefetcher*> fPrefetcherList;
		
		/**
		 * A timer to time the length of a draw.
		*/
		Stopwatch fTimer;
		
		/**
		 * The font of the status text.
		*/
		FontResource* fFont;
		
		/**
		 * Surface for the status text. 
		*/
		StringFontResource* fStatusText;
	};
}

#endif // INC_SPLASHPANEL_H
