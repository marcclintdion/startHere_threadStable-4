    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o17_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o17_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o17_FilePath = "_MODEL_FOLDERS_/o17/o17.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o17_FromHDtoSystemRAM, 0, NULL);                               
            o17_isLoaded = true;                                                             
        }                                                                                   
        if(o17_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o17, o17_COLORMAP, FreeImage_GetWidth(dib_o17),  FreeImage_GetHeight(dib_o17) );     
            delete_o17_FromSystemRAM();                                                      
            o17_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o17_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o17_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o17_POSITION[0] + moveSet[0], 
                                                o17_POSITION[1] + moveSet[1], 
                                                o17_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o17_ROTATION[0], 
                                                o17_ROTATION[1], 
                                                o17_ROTATION[2],  
                                                o17_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o17_ROTATION[0], 
                                                o17_ROTATION[1], 
                                                o17_ROTATION[2], 
                                                o17_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o17_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 34665, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o17_isActive == false && o17_isLoaded == true)                                         
    {                                                                                       
        if(o17_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o17_COLORMAP);                                              
            o17_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o17_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
