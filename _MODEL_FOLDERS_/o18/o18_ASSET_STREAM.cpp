#ifdef WIN32 
void load_o18_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o18 = FreeImage_GetFileType(o18_FilePath, 0);                       
    dib_o18   = FreeImage_Load(fifmt_o18, o18_FilePath, 0);                    
    temp_o18  = dib_o18;                                                      
    dib_o18   = FreeImage_ConvertTo32Bits(temp_o18);                          
    FreeImage_Unload(temp_o18);                                            

    if( dib_o18 != NULL )                                                    
    {                                                                       
        pixels_o18 = (BYTE*)FreeImage_GetBits(dib_o18);                       
    }                                                                     

    o18_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o18_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o18 != NULL )                                                    
    {                                                                       
        free(pixels_o18);                                                    
        FreeImage_Unload(dib_o18);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
