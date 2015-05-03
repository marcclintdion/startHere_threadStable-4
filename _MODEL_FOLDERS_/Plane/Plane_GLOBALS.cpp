void  load_Plane_FromHDtoSystemRAM(void*);                                     
void  delete_Plane_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_Plane;                                                
FIBITMAP            *dib_Plane;                                                
FIBITMAP           *temp_Plane;                                                
BYTE             *pixels_Plane;                                                  
//-------------------------------------------------------------
bool   Plane_isLoadedFromDriveAndWaiting             = false;                  
bool   Plane_isLoaded                                = false;                  
char  *Plane_FilePath;                                                         
bool   Plane_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat Plane_POSITION[]             = { 0.000000f, 0.000000f, 0.000000f, 1.0 }; 
GLfloat Plane_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat Plane_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint Plane_VBO; 
GLuint Plane_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint Plane_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat Plane_boundingBox[6]; 

//===================================================================================================================
void load_Plane_VBOs(void)  
{ 
      #include    "Plane.cpp" 
      glGenBuffers(1,              &Plane_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, Plane_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(Plane), Plane, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "Plane_INDICES.cpp"   
      glGenBuffers(1,              &Plane_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Plane_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Plane_INDICES), Plane_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
