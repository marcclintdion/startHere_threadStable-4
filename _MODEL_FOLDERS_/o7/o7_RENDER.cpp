    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o7_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o7_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o7_FilePath = "_MODEL_FOLDERS_/o7/o7.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o7_FromHDtoSystemRAM, 0, NULL);                               
            o7_isLoaded = true;                                                             
        }                                                                                   
        if(o7_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o7, o7_COLORMAP, FreeImage_GetWidth(dib_o7),  FreeImage_GetHeight(dib_o7) );     
            delete_o7_FromSystemRAM();                                                      
            o7_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o7_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o7_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o7_POSITION[0] + moveSet[0], 
                                                o7_POSITION[1] + moveSet[1], 
                                                o7_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o7_ROTATION[0], 
                                                o7_ROTATION[1], 
                                                o7_ROTATION[2],  
                                                o7_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o7_ROTATION[0], 
                                                o7_ROTATION[1], 
                                                o7_ROTATION[2], 
                                                o7_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o7_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 38469, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o7_isActive == false && o7_isLoaded == true)                                         
    {                                                                                       
        if(o7_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o7_COLORMAP);                                              
            o7_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o7_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
