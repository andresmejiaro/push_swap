#%%
import random
import subprocess
#%%
output = subprocess.run(["ls", "-l"], capture_output=True)
print(output.stdout)

#%%

s = [str(t+1) for t in range(500)]
s = random.sample(s,500)
output = subprocess.Popen(["./push_swap"] + s )

#    print(output.stdout)
    #output2 =subprocess.run(["wc","-l"],stdin=output.stdout)
    #output3 = subprocess.run(["./checker_Mac"] + s,stdin=output.stdout)





# %%
# %%


# %%
