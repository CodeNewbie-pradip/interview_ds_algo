class Solution {
public:
    string fractionAddition(string exp) {
        int n=exp.size();
        int nume=0;
        int deno=1;
        
        int i=0;
        
        while(i<n){
            
            int currNum=0;
            int currDeno=0;
            
            bool isNeg=(exp[i]=='-');
                
            if(exp[i]=='+' || exp[i]=='-'){
                i++;
            }
            
            while(i<n && isdigit(exp[i])){
                int val =exp[i]-'0';
                currNum=(currNum*10)+val;
                i++;
            }
            i++; //here is the divide symbol that's why one extra i++;
            
            
            //here is apply symbol on numerator valu
            if(isNeg){
                currNum*=-1;
            }
            
            while(i<n && isdigit(exp[i])){
                int val=exp[i]-'0';
                currDeno=(currDeno*10)+val;
                i++;
            }
            
            nume=nume*currDeno+deno*currNum;
            deno=deno*currDeno;
        }
        
        //gcd
        int GCD=abs(__gcd(nume, deno));
        nume/=GCD;
        deno/=GCD;
        
        return to_string(nume)+'/'+to_string(deno);
    }
};