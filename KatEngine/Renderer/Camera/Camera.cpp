#include "Camera.h"

using namespace kat;

Camera::Camera() {
	projection = glm::mat4();
	dirty = false;
	projectionView = glm::mat4();
	position = glm::vec3(0, 0, 0);
	rotation = glm::quat();
}

void Camera::setPosition(glm::vec3 newPos) {
	position = newPos;
}

void Camera::setPosition(float x, float y, float z) {
	position = glm::vec3(x, y, z);
}

void Camera::translate(glm::vec3 translation) {
	position += translation;
}

void Camera::translate(float dx, float dy, float dz) {
	position += glm::vec3(dx, dy, dz);
}

void Camera::setRotation(glm::quat rot) {
	rotation = rot;
}

void Camera::setRotation(float x, float y, float z) {
	rotation = glm::quat(glm::vec3(x, y, z));
}

void Camera::setRotation(glm::vec3 euler) {
	rotation = glm::quat(euler);

}

void Camera::rotate(glm::quat rot) {
	rotation *= rot;
}

void Camera::rotate(float x, float y, float z) {
	rotation *= glm::quat(glm::vec3(x, y, z));
}

void Camera::rotate(glm::vec3 euler) {
	rotation *= glm::quat(euler);
}