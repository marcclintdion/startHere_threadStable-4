    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(Cube_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(Cube_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            Cube_FilePath = "_MODEL_FOLDERS_/Cube/Cube.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_Cube_FromHDtoSystemRAM, 0, NULL);                               
            Cube_isLoaded = true;                                                             
        }                                                                                   
        if(Cube_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_Cube, Cube_COLORMAP, FreeImage_GetWidth(dib_Cube),  FreeImage_GetHeight(dib_Cube) );     
            delete_Cube_FromSystemRAM();                                                      
            Cube_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, Cube_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Cube_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, Cube_POSITION[0] + moveSet[0], 
                                                Cube_POSITION[1] + moveSet[1], 
                                                Cube_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    Cube_ROTATION[0], 
                                                Cube_ROTATION[1], 
                                                Cube_ROTATION[2],  
                                                Cube_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, Cube_ROTATION[0], 
                                                Cube_ROTATION[1], 
                                                Cube_ROTATION[2], 
                                                Cube_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, Cube_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(Cube_isActive == false && Cube_isLoaded == true)                                         
    {                                                                                       
        if(Cube_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &Cube_COLORMAP);                                              
            Cube_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        Cube_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
