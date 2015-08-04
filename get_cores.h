#ifndef GET_CORES_H
#define GET_CORES H


//Finds out how many cores the PC has
//Only works with LINUX !


int get_cores()
{
    FILE *fp;
    int c;
    system("touch cores.txt");
    fp = fopen("cores.txt", "rw+");

    fscanf(fp,"%d",&c);
    if(feof(fp))
    {
        system("cat /proc/cpuinfo | grep processor | wc -l >> cores.txt");

    }
    else
    {
        fclose(fp);
        return c;
    }

    fclose(fp);
    fp = fopen("cores.txt","r");
    fscanf(fp,"%d",&c);
    fclose(fp);
    return c;


}












#endif
