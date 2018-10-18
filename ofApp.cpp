#include "ofApp.h"

#include <random>

#include <vector>

#include <iostream>

// Fitness function
double ofApp::function(double * coords, unsigned int dim)
{
	double sum1 = 0;

	double sum2 = 0;

	for(unsigned int index = 1; index <= dim; ++index)
	{
		sum1 += pow((coords[index - 1] + pow(-1.0, index) * (index % 4)), 2);
		
		sum2 += pow(coords[index - 1], index);	
	}

	double result = (-1.0) * sqrt(sum1) + sin(sum2);

	return result;
}

void ofApp::createVertices()
{
	mesh.clearVertices();

	unsigned int pointCount = m_checks * m_checks * m_checks;

	std::random_device device;
	std::uniform_real_distribution<double> distribution(-8.0, 8.0);

	for(unsigned int index = 0; index < pointCount; ++index)
	{
		double x = distribution(device);
		double y = distribution(device);
		double z = distribution(device);

		double coord [] {x,y,z};

		double fitness = function(coord, 3);
		
		ofVec3f point(x,y,z);
		mesh.addVertex(point);

		if(fitness > m_bestFitness)
		{
			m_bestFitness = fitness;
		}
	}
}

void ofApp::createColors(unsigned int exp)
{
	mesh.clearColors();

	// Create Colors
	for(int z = 0; z < m_checks; ++z)
	{
		// the z position of the current vertex
		double currentZ = ((double)z / (double)m_perUnit) - ((double)m_size / 2.0);

		for(int y = 0; y < m_checks; ++y)
		{
				double currentY = ((double)y / (double)m_perUnit) - ((double)m_size / 2.0);

			for(int x = 0; x < m_checks; ++x)
			{
				// the x position of the current vertex
				double currentX = ((double)x / (double)m_perUnit) - ((double)m_size / 2.0);
				
				double coord [] = {currentX, currentY, currentZ};

				double fitness = function(coord, 3);

				double closeness = (fitness / m_bestFitness);

				for(unsigned int i = 0; i < exp; ++i)
				{
					closeness *= closeness;
				}

				// 255 0   0   0
				// 255 255 255 255

				int r = 255;
				int g = 255.0 * closeness;
				int b = 255.0 * closeness;;
				int a = 255.0 * closeness; 

				mesh.addColor(ofColor(r,g,b,a));
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::setup()
{
	m_bestFitness = -DBL_MAX;

	ofEnableDepthTest();

	// size is from -8 to 8
	m_size = 16;
	// how many vertices per 1 unit
	m_perUnit = 8;
	// square root of the number of vertices
	m_checks = m_perUnit * m_size;

	// Create Verticies
	for(int z = 0; z < m_checks; ++z)
	{
		// the z position of the current vertex
		double currentZ = ((double)z / (double)m_perUnit) - ((double)m_size / 2.0);

		for(int y = 0; y < m_checks; ++y)
		{
				double currentY = ((double)y / (double)m_perUnit) - ((double)m_size / 2.0);

			for(int x = 0; x < m_checks; ++x)
			{
				// the x position of the current vertex
				double currentX = ((double)x / (double)m_perUnit) - ((double)m_size / 2.0);

				// pass in these coordinates to the fitness function to get the y position
				double coord [] = {currentX, currentY, currentZ};

				// the y position of the current vertex
				double fitness = function(coord, 3);
			
				ofVec3f point(currentX, currentY, currentZ);
				mesh.addVertex(point);

				if(fitness > m_bestFitness)
				{
					m_bestFitness = fitness;
				}
			}
		}
	}

	createVertices();

	createColors(0);	

	// Initialize the camera closer to our graph
	cam.setTarget(glm::vec3(0.0f,-5.0f,0.0f));
	cam.setDistance(20.0f);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackgroundGradient(ofColor(65,62,50), ofColor(25,22,10));	

	cam.begin();

	mesh.enableColors();
	mesh.drawVertices();
	mesh.disableColors();

	ofSetColor(255,0,0);

	ofDrawSphere(1.0167,-2.0078,3.0347,0.25);

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	createColors(key - '0');
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
