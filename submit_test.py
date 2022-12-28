import subprocess, traceback, os, sys

run_code = sys.argv[2]

problem_id = sys.argv[1]

folder_path = f"all_data/{problem_id}"

test_cases = [
	o.name[:-3]
		for o in os.scandir(folder_path)
			if o.is_file() and o.name.endswith('.in')
]
test_cases.sort()

fail = False

for c in test_cases:
	if fail:
		break
	print(c+": \033[1m\033[33mRunning\033[0m", end=' ', flush=True)
	try:
		outp = subprocess.run(
			[run_code],
			stdin=open(folder_path+'/'+c+'.in', 'r'),
			capture_output=True,
			text=True,
			timeout=2)

		# print("\rDone!", flush=True)
		if outp.returncode != 0:
			print("\r"+c+": \033[1m\033[31mERR\033[0m       ", flush=True)
			fail = True
		elif outp.stdout.split() == open(folder_path+'/'+c+'.out', 'r').read().split():
			print("\r"+c+": \033[1m\033[32mOK\033[0m       ", flush=True)
		else:
			print("\r"+c+": \033[1m\033[31mWA\033[0m       ", flush=True)
			fail = True

		# print(outp.stdout)
	except subprocess.TimeoutExpired as err:
		print("\r"+c+": \033[1m\033[31mTLE\033[0m       ", flush=True)
		fail = True
	except subprocess.CalledProcessError as err:
		print("\r"+c+": \033[1m\033[31mERR\033[0m       ", flush=True)
		print(traceback.format_exc())
	except Exception as err:
		print(traceback.format_exc())

if not fail:
	print("\033[1m\033[32mAC\033[0m       ", flush=True)
