// ModelFile.cpp
//
// Do not put doxygen comments in .cpp files. Only normal comments
// Class for loading and managing models
// Not everything is commented. NO doxygen comments here - just
// internal comments for developer.
//
// Version
// 01 26/09/2007 Mark Iskra
//    Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "ModelFile.h"

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Prototypes

//----------------------------------------------------------------------------
// Function implementations

// Clears all loaded models and templates ** not complete
void ModelFile::Clear()
{
	map<string, BlockModel>::iterator curModel;

	cout << "in Clear" << endl; // *** got to complete this stuff

}

//----------------------------------------------------------------------------
// Loads all models listed in a text file - ok
void ModelFile::LoadModels(string listFile)
{
	ifstream modelList(listFile.c_str());
	string curModel;
	BlockModel model;

	while(getline(modelList, curModel))
	{
		// who deleted this *(&*&() code?

		modelFile.close();
	}

	modelList.close();
}

//----------------------------------------------------------------------------
// Loads all room templates listed in a text file - prints message on screen too
void ModelFile::LoadTemplates(string templateFile)
{
	ifstream input(templateFile.c_str());

	Template curTemplate;
	TemplateObject curObject;

	string curModel;
	float x,y,z;
	float angle;

	while(input && getline(input, curTemplate.name))
	{
		curTemplate.objects.clear();

		cout << "Loading template \"" << curTemplate.name << "\"" << endl;

		while(getline(input, curModel) && curModel != "$")
		{
			input >> x >> y >> z >> angle;

			curObject.pos.x = x;
			curObject.pos.y = y;
			curObject.pos.z = z;
			curObject.angle = angle;
			curObject.model = GetModel(curModel);

			// Add to template if model is valid
			if(curObject.model)
				curTemplate.objects.push_back(curObject);

			getline(input, curModel);
		}

		if(input)
			m_templates.push_back(curTemplate);
	}

	cout << "Loaded " << m_templates.size() << " templates" << endl;

	input.close();
}

//----------------------------------------------------------------------------
// Draws specified room template - prints message for failure
void ModelFile::RenderTemplate(int templateID)
{
	vector<TemplateObject>::iterator curObject, templateEnd; 

	// TODO: Use display list here if I have time
	if(templateID >= 0 && templateID < m_templates.size())
	{
		curObject = m_templates[templateID].objects.begin();
		templateEnd = m_templates[templateID].objects.end();

		while(curObject != templateEnd)
		{
			glPushMatrix();
			glTranslatef(curObject->pos.x, curObject->pos.y, curObject->pos.z);
			glRotatef(curObject->angle, 0.0f, 1.0f, 0.0f);

			curObject->model->Render();

			glPopMatrix(); // don't change this

			curObject++;
		}
	}
	else
	{
		cout << "Bad template ID" << endl;
	}
}

//----------------------------------------------------------------------------
// Retrieves the ID number of a template based on name, error msg on screen
int ModelFile::GetTemplateID(string templateName)
{
	bool found = false;
	int templateID = 0;

	for(int curTemplate = 0; curTemplate < m_templates.size() && !found; curTemplate++)
	{
		if(stricmp(m_templates[curTemplate].name.c_str(), templateName.c_str()) == 0)
		{
			templateID = curTemplate;
			found = true;
		}
	}

	if(!found)
		cout << "Missing template \"" << templateName.c_str() << "\"" << endl;

	return templateID; // 0 means not found
}

//----------------------------------------------------------------------------

BlockModel* ModelFile::GetModel(string modelName)
{
	map<string, BlockModel>::iterator result;

	result = m_models.find(modelName);

	if(result != m_models.end())
	{
		return &result->second;
	}
	else
	{
		cout << "Error: Unknown model " << modelName.c_str() << endl;
		return 0;
	}
}

//----------------------------------------------------------------------------

ModelFile *ModelFile::GetInstance()
{
	static ModelFile *modelFile = new ModelFile();

	return modelFile;
}

//----------------------------------------------------------------------------


