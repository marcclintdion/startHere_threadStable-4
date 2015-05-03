    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o10_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o10_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o10_FilePath = "_MODEL_FOLDERS_/o10/o10.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o10_FromHDtoSystemRAM, 0, NULL);                               
            o10_isLoaded = true;                                                             
        }                                                                                   
        if(o10_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o10, o10_COLORMAP, FreeImage_GetWidth(dib_o10),  FreeImage_GetHeight(dib_o10) );     
            delete_o10_FromSystemRAM();                                                      
            o10_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o10_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o10_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o10_POSITION[0] + moveSet[0], 
                                                o10_POSITION[1] + moveSet[1], 
                                                o10_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o10_ROTATION[0], 
                                                o10_ROTATION[1], 
                                                o10_ROTATION[2],  
                                                o10_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o10_ROTATION[0], 
                                                o10_ROTATION[1], 
                                                o10_ROTATION[2], 
                                                o10_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o10_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 35970, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o10_isActive == false && o10_isLoaded == true)                                         
    {                                                                                       
        if(o10_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o10_COLORMAP);                                              
            o10_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o10_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
