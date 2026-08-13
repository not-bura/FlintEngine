#pragma once

#define FLINT_ENGINE_GL_VULKAN
#include <vulkan/vulkan_core.h>
#include <optional>
#include "Domain/Collections/Array.hpp"

namespace FlintEngine
{
	class GraphicsDevice
	{
	private:
#ifdef FLINT_ENGINE_GL_VULKAN
		VkPhysicalDevice m_instance;

		GraphicsDevice(VkPhysicalDevice instance);
#endif
	};

	class GL
	{
	private:
#ifdef FLINT_ENGINE_GL_VULKAN
		VkInstance m_instance;

		GL(VkInstance instance);
#endif // FLINT_ENGINE_GL_VULKAN

	public:
		GL(const GL&) = delete;
		GL(GL&& other) noexcept;

		~GL();

		Array<GraphicsDevice> GetPhysicalDevices() const;

		static std::optional<GL> TryCreate();
	};
}
