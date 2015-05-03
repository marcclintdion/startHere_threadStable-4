#ifdef WIN32 
void load_o19_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o19 = FreeImage_GetFileType(o19_FilePath, 0);                       
    dib_o19   = FreeImage_Load(fifmt_o19, o19_FilePath, 0);                    
    temp_o19  = dib_o19;                                                      
    dib_o19   = FreeImage_ConvertTo32Bits(temp_o19);                          
    FreeImage_Unload(temp_o19);                                            

    if( dib_o19 != NULL )                                                    
    {                                                                       
        pixels_o19 = (BYTE*)FreeImage_GetBits(dib_o19);                       
    }                                                                     

    o19_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o19_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o19 != NULL )                                                    
    {                                                                       
        free(pixels_o19);                                                    
        FreeImage_Unload(dib_o19);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
