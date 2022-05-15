

#include "Model.h"

Model::Model()
{
    
    triangles.clear();
}

int Model::numTriangles()
{
    return (int)triangles.size();
}

Triangle3D Model::operator[](int i)
{
    return triangles[i];
}
void Model::transform(Matrix4 other)
{ 
    for(int i = 0; i<numTriangles(); i++)
    {
      if(triangles[i].shouldDraw){
        triangles[i].transform(other);
      }
    }
}
void Model::readFromOBJFile(string filepath, Color pFillColor)
{
    ifstream objFile(filepath);
    if(objFile.is_open())
    {
        vector<Vector4> vertices;
        string line;
        while(getline(objFile, line))
        {
            vector<string> words;
            istringstream s(line);
            string myWord;
            while(getline(s, myWord, ' '))
            {
                words.push_back(myWord);
            }
            if(words[0] == "v")
            {
                vertices.push_back(Vector4(atof(words[1].c_str()), atof(words[2].c_str()), atof(words[3].c_str()), 1.0f));
            }
            else if(words[0] == "f")
            {
                if(words.size() == 4)
                {
                    Vector4 v1 = vertices[atoi(words[1].c_str())-1];
                    Vector4 v2 = vertices[atoi(words[2].c_str())-1];
                    Vector4 v3 = vertices[atoi(words[3].c_str())-1];
                    
                    triangles.push_back(Triangle3D(v1, v2, v3, pFillColor, pFillColor, pFillColor));
                }
                else if(words.size() == 5)
                {
                    Vector4 v1 = vertices[atoi(words[1].c_str())-1];
                    Vector4 v2 = vertices[atoi(words[2].c_str())-1];
                    Vector4 v3 = vertices[atoi(words[3].c_str())-1];
                    Vector4 v4 = vertices[atoi(words[4].c_str())-1];
                    
                    Triangle3D t1 = Triangle3D(v1, v2, v3, pFillColor, pFillColor, pFillColor);
                    Triangle3D t2 = Triangle3D(v1, v3, v4, pFillColor, pFillColor, pFillColor);
                    
                    triangles.push_back(t1);
                    triangles.push_back(t2);
                    
                }
            }
        }

        objFile.close();
    }
}

void Model::homogenize()
{
	for(int i = 0; i < triangles.size(); i++)
	{
		float clip = triangles[i].v1.w;
    triangles[i].v1.x = triangles[i].v1.x/clip;
    triangles[i].v1.y = triangles[i].v1.y/clip;
    triangles[i].v1.z = triangles[i].v1.z/clip;
    triangles[i].v1.w = 1;

    clip = triangles[i].v2.w;
    triangles[i].v2.x = triangles[i].v2.x/clip;
    triangles[i].v2.y = triangles[i].v2.y/clip;
    triangles[i].v2.z = triangles[i].v2.z/clip;
    triangles[i].v2.w = 1;

    clip = triangles[i].v3.w;
    triangles[i].v3.x = triangles[i].v3.x/clip;
    triangles[i].v3.y = triangles[i].v3.y/clip;
    triangles[i].v3.z = triangles[i].v3.z/clip;
    triangles[i].v3.w = 1;
  }
}

void Model::performBackfaceCulling(Vector4 eye, Vector4 spot){
  for (int i = 0; i < triangles.size(); i++){
    Vector4 look = spot - eye;
		Vector4 a = triangles[i].v3 - triangles[i].v2;
		Vector4 b = triangles[i].v1 - triangles[i].v2;
		Vector4 normal = b.cross(a).normalize();
		if (normal.dot(look) > 0.0){
			triangles[i].shouldDraw = false;
      //triangles[i].c1 = Blue;
      //triangles[i].c2 = Blue;
      //triangles[i].c3 = Blue;

		}
	}
}

