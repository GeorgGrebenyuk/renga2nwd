#pragma once
#include "pch.h"

static Renga::IApplicationPtr renga_application;
class object_3d_info {
public:
	object_3d_info(std::vector<const char*> material_names_data,
		std::vector<std::vector<unsigned short>> material_colors_data, std::vector<Renga::IGridPtr> geometry_data)
	{
		this->geometry = geometry_data;
		this->material_colors = material_colors_data;
		this->material_names = material_names_data;
	}
	object_3d_info() {}
	std::vector<const char*> material_names;
	std::vector<std::vector<unsigned short>> material_colors;
	std::vector<Renga::IGridPtr> geometry;
	//properties
	/*
	* if export for Grid2Material -- they are empty
	*/
	const char* object_name;
	const char* object_guid;

	
};
/// <summary>
/// Class for getting info from model about objects
/// </summary>
class renga_data
{
public: 
	renga_data(Renga::IApplicationPtr application, int mode);
	std::map<int, object_3d_info> objects_3d_info;
	//���������� �������� �� ������� � �� ����� (� ����� ��� �������� ��� ������)
	std::map<Renga::ILevelPtr, std::map<const char*, std::vector<int>>> levels_objects;
	std::map<const char *, std::vector<int>> non_levels_objects;
	const char* project_path;
private:
	void start_sort_by_level_and_type();
	//void get_properties(Renga::IModelObjectPtr model_object);
	//for materials and colors
	void get_material(Renga::IModelObjectPtr model_object, Renga::Color* color, const char** material_name);
	void get_layered_material(int sub_object_position, Renga::IModelObjectPtr model_object, Renga::Color* color, const char** material_name);
	void get_style(Renga::IModelObjectPtr model_object, Renga::Color* color);
	void get_grids_color(GUID object_type, int grid_type, Renga::Color* color);
};


