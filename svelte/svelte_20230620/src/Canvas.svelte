<script lang="ts">
    import { onMount } from 'svelte';

    onMount(async () => {
        interface Rect {
            x: number;
            y: number;
            width: number;
            height: number;
            color: string;
        }
    
        interface Ball extends Rect {
            speedX: number;
            speedY: number;
        }
    
        interface Bar extends Rect {
            speed: number;
        }
    
        const scoreDiv = document.getElementById("score") as HTMLDivElement;
        const canvas = document.getElementById("canvas") as HTMLCanvasElement;
        const ctx = canvas.getContext("2d") as CanvasRenderingContext2D;
        
        let score: number = 0;
    
        canvas.width = 500;
        canvas.height = 500;
    
        const ball: Ball = {
            x: 0,
            y: 0,
            width: 10,
            height: 10,
            speedX: 1,
            speedY: 1,
            color: "rgb(255, 255, 255)"
        }
    
        const bar: Bar = {
            x: 0,
            y: 0,
            width: 10,
            height: 100,
            speed: 10,
            color: "rgb(0, 255, 255)"
        }
    
        const draw = () => {
            if (ctx != null) {
                ctx.fillStyle = "rgb(0, 0, 0)";
                ctx.fillRect(0, 0, canvas.width, canvas.height);
        
                ball.x += ball.speedX;
                ball.y += ball.speedY;
        
                if (ball.x > canvas.width - ball.width) {
                    ball.speedX *= -1;
                }
        
                if (ball.y < 0 || ball.y > canvas.height - ball.height) {
                    ball.speedY *= -1;
                }
        
                if (ball.x < bar.x + bar.width && ball.x > bar.x 
                    && ball.y < bar.y + bar.height && ball.y > bar.y) {
                        if (ball.speedX < 0) {
                            ball.speedX *= -1;
                            score++;
                            scoreDiv.innerText = `${score}`;
                        }
                    }
                
                if (ball.x < 0) {
                    score--;
                    ball.x = canvas.width - 50;
                    ball.y = Math.random() * canvas.height;
                    scoreDiv.innerText = `${score}`;
                }
        
                ctx.fillStyle = ball.color;
                ctx.fillRect(ball.x, ball.y, ball.width, ball.height);
        
                ctx.fillStyle = bar.color;
                ctx.fillRect(bar.x, bar.y, bar.width, bar.height);
            }
        }
    
        const handleKeyDown = (event: KeyboardEvent) => {
            const key = event.key;
            
            switch (key) {
                case "ArrowUp":
                    bar.y -= bar.speed;
                    if (bar.y < 0) {
                        bar.y = 0;
                    }
                    break;
                
                case "ArrowDown":
                    bar.y += bar.speed;
                    if (bar.y > canvas.height - bar.height) {
                        bar.y = canvas.height - bar.height;
                    }
                    break;
            
                default:
                    break;
            }
        }
    
        document.addEventListener('keydown', handleKeyDown);
    
        setInterval(draw, 0.1);
    });
</script>

<canvas id="canvas"></canvas>
<div id="score">
    0:0
</div>

<style>
    #canvas {
        width: 500px;
        height: 500px;
    }
</style>