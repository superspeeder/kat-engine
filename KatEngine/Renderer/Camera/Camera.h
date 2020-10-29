#pragma once

#include <glm/common.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/quaternion_common.hpp>
#include <glm/ext/quaternion_float.hpp>

namespace kat {
	class Camera {
	private:
		glm::mat4 projection;
		glm::mat4 projectionView;
		glm::vec3 position;
		glm::quat rotation;
		bool dirty;
	public:

		Camera();
		
		inline bool isDirty() { return dirty; };
		inline void markDirty() { dirty = true; };

		virtual void update() { };

		void setPosition(glm::vec3 newPos);
		void setPosition(float x, float y, float z);

		void translate(glm::vec3 translation);
		void translate(float dx, float dy, float dz);

		void setRotation(glm::quat rot);
		void setRotation(float x, float y, float z); // Euler Angles
		void setRotation(glm::vec3 euler); // Euler Angles

		void rotate(glm::quat rotation);
		void rotate(float x, float y, float z); // Euler Angles
		void rotate(glm::vec3 euler); // Euler Angles


		glm::mat4 getPV();




	};
}