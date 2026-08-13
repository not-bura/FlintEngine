#include "../GL.h"

#ifdef FLINT_ENGINE_GL_VULKAN
#include <vulkan/vulkan_core.h>
#include <optional>
#include "Domain/Collections/Array.hpp"
#include "Domain/Type.h"

using namespace FlintEngine;
using namespace std;

GraphicsDevice::GraphicsDevice(VkPhysicalDevice instance)
	: m_instance(instance)
{
}

GL::GL(VkInstance instance)
	: m_instance(instance)
{
}

GL::GL(GL&& other) noexcept
	: m_instance(other.m_instance)
{
	other.m_instance = nullptr;
}

GL::~GL()
{
	if (m_instance != nullptr)
	{
		vkDestroyInstance(m_instance, nullptr);
		m_instance = nullptr;
	}
}

Array<GraphicsDevice> GL::GetPhysicalDevices() const
{
	ui4 _deviceCount;
	auto _result = vkEnumeratePhysicalDevices(m_instance, &_deviceCount, nullptr);
	if (_result != VK_SUCCESS)
	{
		return Array<GraphicsDevice>::Empty();
	}

	auto _buffer = Array<VkPhysicalDevice>{ _deviceCount };
	_result = vkEnumeratePhysicalDevices(m_instance, &_deviceCount, static_cast<VkPhysicalDevice*>(_buffer.Pointer()));
	if (_result != VK_SUCCESS)
	{
		return Array<GraphicsDevice>::Empty();
	}

	return _buffer.Move<GraphicsDevice>();
}

optional<GL> GL::TryCreate()
{
	VkInstanceCreateInfo _instanceCreateInfo{};

	VkInstance _instance;
	auto _result = vkCreateInstance(&_instanceCreateInfo, nullptr, &_instance);
	if (_result != VK_SUCCESS)
	{
		return nullopt;
	}

	return GL{ _instance };
}
#endif
