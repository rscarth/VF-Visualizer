//Set of default examples for vector fields

#include "equations.h"

namespace VectorField { namespace Equations {
	namespace ThreeD {
		float* rotationalVectorField(float pos[2]){
			float i = pos[1];
			float j = pos[0]*-1;
			float k = pos[2];

			float pos_trans[3] = {i,j,k};

			return &pos_trans[2];
		};
	}

	namespace TwoD {
		float* rotationalVectorField(float pos[2]){
			float i = pos[1];
			float j = pos[0] * -1;

			float pos_trans[2] = {i,j};

			return &pos_trans[1];
		};
	}
}}