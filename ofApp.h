#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:
		ofEasyCam cam;
		ofVboMesh mesh;

		int m_size;
		int m_perUnit;
		int m_checks;

		double m_bestFitness;

	private:
		double function(double * coords, unsigned int dim);

		void createColors(unsigned int exp);

		void createVertices();
};
