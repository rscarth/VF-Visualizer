//Set of default examples for vector fields

#pragma once

#include "vertex.h"

namespace VectorField { namespace Equations {
	namespace ThreeD {
		float* rotationalVectorField(float pos[2]);
	}

	namespace TwoD {
		float* rotationalVectorField(float pos[2]);
	}

}}