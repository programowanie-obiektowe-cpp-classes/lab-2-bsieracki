#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource;

public:
    ResourceManager() : resource(new Resource()){};
    ResourceManager(const ResourceManager& resourceManager) : resource(new Resource(*resourceManager.resource)){};
    ResourceManager& operator=(const ResourceManager& resourceManager)
    {
        if (this != &resourceManager) {
            delete resource;
            resource = new Resource(*resourceManager.resource);
        }
        return *this;
    };
    ResourceManager(ResourceManager&& resourceManager) : resource(resourceManager.resource)
    {
        resourceManager.resource = nullptr;
    }
    ResourceManager& operator=(ResourceManager&& resourceManager)
    {
        if (this != &resourceManager) {
            delete resource;
            resource = resourceManager.resource;
            resourceManager.resource = nullptr;
        }
        return *this;
    }
    ~ResourceManager()
    {
        delete resource;
    };
    double get() const { return resource->get(); }
};
