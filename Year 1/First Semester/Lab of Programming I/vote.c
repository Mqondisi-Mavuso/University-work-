
int main (void)
{
    int n,m,i; //n = the number of candidates and m= number of votes;
    scanf("%d %d", &n, &m);

    while (n !=0 && m != 0)
    {
        int candidates[200], votes[m];
        for (i = 0; i < m; i++)
        {
            scanf("%d", &votes[i]);
        }

        for (i = 0; i < n; i++) //setting the values in candidates to zero
        {
            candidates[i] = 0;
        }
        for (i = 0; i < m ;i++) //putting the votes in the correct candidate array
        {
            candidates[votes[i]-1]++;
        }

        int majority_winner, majority = 0; //determining winner by majority
        for (i = 0; i<n; i++)
        {
            if (candidates[i] > (m/2))
            {
            	majority_winner = i;
                majority = 1;
            }

        }

        int plurality_winner = candidates[0], plurality = 1, index = 0;
        for (i = 1; i < n; i++) // determining winner by plurality
        {
            if (candidates[i] > plurality_winner)
            {
                plurality = 1;
                plurality_winner = candidates[i];
                index = i;
            }
            else if (candidates[i] == plurality_winner)
            {
                plurality = 0;
            }
        }

        if (majority == 1)
        {
            printf("Majoritarian winner %d\n", majority_winner +1);
        }

        else if (plurality == 1)
        {
             printf("Plurality winner %d\n", index + 1 );
        }

        else printf("No winner\n");

        scanf("%d %d", &n, &m);
    }

return 0;
}
