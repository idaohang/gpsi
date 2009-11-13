#include "guiframework/resources/resourcemanager.h"

namespace sdlframework {
	ResourceManager::ResourceManager() {
	}

	ResourceManager ResourceManager::manager() {
		return ResourceManager::fManager;
	}
	
	void ResourceManager::free(VResource* res) {
		res->fRefCount--;
		
		if (res->fRefCount == 0) {
			fResourceList.erase(res->getName());
			delete res;
			res = NULL;
		}
	}
	
	ImageResource* ResourceManager::image(std::string name) {
		if (!HasResource(name)) {
			ImageResource* res = ImageResource::open(name);
			InsertResource(name, res);
			
			return res;
		} else {
			return static_cast<ImageResource*>(GetResource(name));
		}
	}
	
	bool ResourceManager::HasResource(std::string name) {
		return fResourceList.find(name) != fResourceList.end();
	}
	
	void ResourceManager::InsertResource(std::string name, VResource* res) {
		fResourceList[name] = res;
	}
	
	VResource* ResourceManager::GetResource(std::string name) {
		VResource* res = fResourceList[name];
		res->fRefCount++;
	}
	
	ResourceManager ResourceManager::fManager = ResourceManager();
}