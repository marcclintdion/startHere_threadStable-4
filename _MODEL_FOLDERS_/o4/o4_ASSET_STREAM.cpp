#ifdef WIN32 
void load_o4_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o4 = FreeImage_GetFileType(o4_FilePath, 0);                       
    dib_o4   = FreeImage_Load(fifmt_o4, o4_FilePath, 0);                    
    temp_o4  = dib_o4;                                                      
    dib_o4   = FreeImage_ConvertTo32Bits(temp_o4);                          
    FreeImage_Unload(temp_o4);                                            

    if( dib_o4 != NULL )                                                    
    {                                                                       
        pixels_o4 = (BYTE*)FreeImage_GetBits(dib_o4);                       
    }                                                                     

    o4_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o4_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o4 != NULL )                                                    
    {                                                                       
        free(pixels_o4);                                                    
        FreeImage_Unload(dib_o4);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
