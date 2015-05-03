    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(Plane_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(Plane_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            Plane_FilePath = "_MODEL_FOLDERS_/Plane/Plane.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_Plane_FromHDtoSystemRAM, 0, NULL);                               
            Plane_isLoaded = true;                                                             
        }                                                                                   
        if(Plane_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_Plane, Plane_COLORMAP, FreeImage_GetWidth(dib_Plane),  FreeImage_GetHeight(dib_Plane) );     
            delete_Plane_FromSystemRAM();                                                      
            Plane_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, Plane_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Plane_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, Plane_POSITION[0] + moveSet[0], 
                                                Plane_POSITION[1] + moveSet[1], 
                                                Plane_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    Plane_ROTATION[0], 
                                                Plane_ROTATION[1], 
                                                Plane_ROTATION[2],  
                                                Plane_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, Plane_ROTATION[0], 
                                                Plane_ROTATION[1], 
                                                Plane_ROTATION[2], 
                                                Plane_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, Plane_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(Plane_isActive == false && Plane_isLoaded == true)                                         
    {                                                                                       
        if(Plane_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &Plane_COLORMAP);                                              
            Plane_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        Plane_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
